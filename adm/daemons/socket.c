//Cracked by Kafei
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** socket.c
**
** This object represents an open UDP/TCP socket using the MudOS
** socket facilities.
**
** 09-Feb-95. Deathblade. Created.
** 05-Jan-96. Cowl. Added STREAM BINARY connect and listen styles
** 12-Jul-96. Rust. Added write callback.
*/

#include <mudlib.h>
#include <socket.h>
#include <net/socket_err.h>
#include <log.h>

//#define SKTLOG(x,y)	write_file("/open/sktlog",sprintf("%s: %O\n",x,y))
#define SKTLOG(x,y)

/*
** If this is defined, then the specified privilege is needed to create
** an outbound connection
*/
#define REQUIRE_PRIV	"Mudlib:socket"

nosave private int	style;
nosave private int	fdOwned = -1;	/* no socket yet */
nosave private function	read_func;
nosave private function	close_func;
nosave private function write_func;

nosave private mixed *	write_queue = ({ });
nosave private int	blocked;

/* For debug purposes only */
nosave private mixed addr;

void set_write_callback(function f)
{
    write_func = f;
}

int stat_me()
{
    switch ( style )
    {
    case SKT_STYLE_LISTEN:
	printf("%O: listening at %O\n", this_object(), addr);
	printf("    read_func=%O  close_func=%O\n", read_func, close_func);
	break;

    case SKT_STYLE_CONNECT:
	printf("%O: connected to %O\n", this_object(), addr);
	printf("    read_func=%O  close_func=%O\n", read_func, close_func);
	break;

    case SKT_STYLE_UDP:
	printf("%O: UDP at %O\n", this_object(), addr);
	printf("    read_func=%O\n", read_func);
	break;

    case SKT_STYLE_LISTEN_M:
	printf("%O: (mud) listening at %O\n", this_object(), addr);
	printf("    read_func=%O  close_func=%O\n", read_func, close_func);
	break;

    case SKT_STYLE_CONNECT_M:
	printf("%O: (mud) connected to %O\n", this_object(), addr);
	printf("    read_func=%O  close_func=%O\n", read_func, close_func);
	break;

    case SKT_STYLE_INT_ACQUIRE:
	printf("%O: accepted connection from %s\n", this_object(),
	       socket_address(fdOwned));
	printf("    read_func=%O  close_func=%O\n", read_func, close_func);
	break;
    }

    if ( sizeof(write_queue) )
	printf("queue: %O\n", write_queue);

    return 1;
}


//### socket_connect() doesn't take funcptr yet...
/* private */ protected nomask void read_callback(int fd, mixed message)
{
SKTLOG("read_callback: self",this_object());
SKTLOG("read_callback: fd",fd);
    catch(evaluate(read_func, this_object(), message));
}

private nomask void read_udp_callback(int fd, mixed message, string address)
{
SKTLOG("read_udp_callback: self",this_object());
SKTLOG("read_udp_callback: fd",fd);
SKTLOG("read_udp_callback: read_func",read_func);
    catch(evaluate(read_func, this_object(), message, address));
}

private nomask void close_callback(int fd)
{
SKTLOG("close_callback: self",this_object());
SKTLOG("close_callback: fd",fd);
SKTLOG("close_callback: close_func",close_func);

    /* this descriptor is closed. don't try to close again. */
    fdOwned = -1;

    if ( close_func )
    {
	catch(evaluate(close_func, this_object()));
    }

    destruct();
}

//### socket_connect() doesn't take a funcptr yet
/* private */ protected nomask void write_callback(int fd)
{
    mixed tmp;
SKTLOG("write_callback: self",this_object());
SKTLOG("write_callback: fd",fd);
SKTLOG("write_callback: # elem",sizeof(write_queue));

    /*
    ** No longer blocked (can accept new data).
    */
    if ( !sizeof(write_queue) && write_func && blocked )
    {
        write_queue = ({ evaluate(write_func, this_object()) });
    }

    blocked = 0;

    while ( sizeof(write_queue) > 0 )
    {
	int err;

	err = socket_write(fd, write_queue[0]);

	if ( err == EEALREADY )
	{
            // write_callback will get called automatically.
            blocked = 1;
	    return;
	}
        if ( err == EEWOULDBLOCK )
        {
            // write_callback needs to get called manually.
            blocked = 1;
            call_out("write_callback",1,fd);
            return;
        }

	/*
	** Remove the item from the queue.  It has been written.
	*/
	write_queue = write_queue[1..];

	if ( err == EECALLBACK )
	{
	    /* done for now... wait for the next callback */
	    blocked = 1;
	    return;
	}
	if ( err < 0 )
	{
	    error("could not write: " + socket_error(err) + "\n");
	}
	else if ( write_func )
	{
            tmp = evaluate(write_func, this_object());
            if ( sizeof(tmp) )
		write_queue += ({ tmp });
	}
    }
}

/* private */ nomask void release_callback(int fdToAcquire)
{
    int err;

SKTLOG("release_callback: self",this_object());
    fdOwned = fdToAcquire;
SKTLOG("release_callback: fdOwned",fdOwned);
    err = socket_acquire(fdOwned,
			 (: read_callback :),
			 (: write_callback :),
			 (: close_callback :));
SKTLOG("release_callback: err",err);

    if ( err < 0 )
	error("could not release: " + socket_error(err) + "\n");

    /*
    ** Deliver a 0 indicating a new connection (and providing self)
    */
    catch(evaluate(read_func, this_object(), 0));
}

//### socket_listen doesn't take funcptrs yet...
/* private */ protected nomask void listen_callback(int fd)
{
    object	s;
    int		err;

SKTLOG("listen_callback: self",this_object());
SKTLOG("listen_callback: fd",fd);
    fd = socket_accept(fd, (: read_callback :), (: write_callback :));
    s = new(SOCKET, SKT_STYLE_INT_ACQUIRE, read_func, close_func);
SKTLOG("listen_callback: new sock",s);
    err = socket_release(fd, s, "release_callback");
SKTLOG("listen_callback: err",err);
    if ( err < 0 )
	error("could not release: " + socket_error(err) + "\n");
}

//### need a way to protect this from random writes
varargs nomask void send(mixed message, string address)
{
    int	err;

SKTLOG("send: self",this_object());
SKTLOG("send: fd",fdOwned);
SKTLOG("send: # elem",sizeof(write_queue));

    if ( address )
	err = socket_write(fdOwned, message, address);
    else if ( blocked )
    {
	/*
	** If we are blocked, then the socket doesn't want us to send
	** any more.  Place it on our queue for sending later.
	*/
	write_queue += ({ message });
    }
    else
    {
	while ( sizeof(message) )
	{
	    err = socket_write(fdOwned, message);

	    if ( err == EEALREADY )
	    {
		// write_callback will get called automatically.
		blocked = 1;
		write_queue += ({ message });
		return;
	    }
	    if ( err == EEWOULDBLOCK )
	    {
		// write_callback needs to get called manually.
		blocked = 1;
		write_queue += ({ message });
		call_out("write_callback", 1, fdOwned);
		return;
	    }
	    if ( err == EECALLBACK )
	    {
		/*
		** Socket took the message but is blocked until it can
		** write it out.  Set a flag so that we don't write any
		** more until we get the callback.
		*/
		blocked = 1;
		return;
	    }

	    message = "";
	    if ( write_func )
	    {
		message = evaluate(write_func, this_object());
	    }
	}
    }

    if ( err < 0 )
	error("could not write: " + socket_error(err) + "\n");
}

void remove()
{
    int err;

    if ( fdOwned >= 0 )
    {
SKTLOG("remove: self",this_object());
SKTLOG("remove: fdOwned",fdOwned);
	err = socket_close(fdOwned);
SKTLOG("remove: err",err);
	if ( err < 0 )
	    LOG_D->log(LOG_SOCKET,
		       "could not close: " + socket_error(err) + "\n");
    }

    destruct(this_object());
}

nomask mixed *address()
{
    string tmp;
    string host;
    int port;

    tmp = socket_address(fdOwned);
    sscanf(tmp, "%s %d", host, port);
    return ({ host, port });
}

void create(int skt_style, mixed p1, mixed p2, mixed p3)
{
    int err;

    if ( !clonep() )
	return;

SKTLOG("create: self",this_object());
    style = skt_style;
    addr = p1;

    switch ( style )
    {
    case SKT_STYLE_LISTEN:
	read_func = p2;
	close_func = p3;
	fdOwned = socket_create(1 /* STREAM */,
				(: read_callback :),
				(: close_callback :));
	if ( fdOwned < 0 )
	    error("could not create socket: " + socket_error(fdOwned) + "\n");
	if ( (err = socket_bind(fdOwned, p1)) < 0 )
	    error("could not bind socket: " + socket_error(err) + "\n");
	if ( (err = socket_listen(fdOwned, "listen_callback")) < 0 )
	    error("could not listen to socket: " + socket_error(err) + "\n");
SKTLOG("create: SKT_STYLE_LISTEN",fdOwned);
	break;

    case SKT_STYLE_CONNECT:
	read_func = p2;
	close_func = p3;
#ifdef REQUIRE_PRIV
	if ( !check_previous_privilege(REQUIRE_PRIV) )
	{
	    error("Insufficient privs to open an outgoing socket.\n");
	}
#endif
	fdOwned = socket_create(1 /* STREAM */,
				(: read_callback :),
				(: close_callback :));
	if ( fdOwned < 0 )
	    error("could not create socket: " + socket_error(fdOwned) + "\n");
	err = socket_connect(fdOwned, p1, "read_callback", "write_callback");
	if ( err < 0 )
	    error("could not listen to socket: " + socket_error(err) + "\n");
SKTLOG("create: SKT_STYLE_CONNECT",fdOwned);
SKTLOG("create: close_func",close_func);
	break;

    case SKT_STYLE_LISTEN_B:
        read_func = p2;
        close_func = p3;
        fdOwned = socket_create(3 /* STREAM BINARY */,
                                (: read_callback :),
                                (: close_callback :));
        if ( fdOwned < 0 )
            error("could not create socket: " + socket_error(fdOwned) + "\n");
        if ( (err = socket_bind(fdOwned, p1)) < 0 )
            error("could not bind socket: " + socket_error(err) + "\n");
        if ( (err = socket_listen(fdOwned, "listen_callback")) < 0 )
            error("could not listen to socket: " + socket_error(err) + "\n");
SKTLOG("create: SKT_STYLE_LISTEN_B",fdOwned);
        break;

    case SKT_STYLE_CONNECT_B:
#ifdef REQUIRE_PRIV
	if ( !check_previous_privilege(REQUIRE_PRIV) )
	{
	    error("Insufficient privs to open an outgoing socket.\n");
	}
#endif
        read_func = p2;
        close_func = p3;
        fdOwned = socket_create(3 /* STREAM BINARY */,
                                (: read_callback :),
                                (: close_callback :));
        if ( fdOwned < 0 )
            error("could not create socket: " + socket_error(fdOwned) + "\n");
        err = socket_connect(fdOwned, p1, "read_callback", "write_callback");
        if ( err < 0 )
            error("could not listen to socket: " + socket_error(err) + "\n");
SKTLOG("create: SKT_STYLE_CONNECT_B",fdOwned);
SKTLOG("create: close_func",close_func);
        break;

    case SKT_STYLE_UDP:
#ifdef REQUIRE_PRIV
	if ( !check_previous_privilege(REQUIRE_PRIV) )
	{
	    error("Insufficient privs to open a datagram socket.\n");
	}
#endif
	read_func = p2;
	fdOwned = socket_create(2 /* DATAGRAM */, (: read_udp_callback :));
	if ( fdOwned < 0 )
	    error("could not create socket: " + socket_error(fdOwned) + "\n");
	if ( (err = socket_bind(fdOwned, p1)) < 0 )
	    error("could not bind socket: " + socket_error(err) + "\n");
SKTLOG("create: SKT_STYLE_UDP",fdOwned);
	break;

    case SKT_STYLE_LISTEN_M:
	read_func = p2;
	close_func = p3;
	fdOwned = socket_create(0 /* MUD */,
				(: read_callback :),
				(: close_callback :));
	if ( fdOwned < 0 )
	    error("could not create socket: " + socket_error(fdOwned) + "\n");
	if ( (err = socket_bind(fdOwned, p1)) < 0 )
	    error("could not bind socket: " + socket_error(err) + "\n");
	if ( (err = socket_listen(fdOwned, "listen_callback")) < 0 )
	    error("could not listen to socket: " + socket_error(err) + "\n");
SKTLOG("create: SKT_STYLE_LISTEN_M",fdOwned);
	break;

    case SKT_STYLE_CONNECT_M:
#ifdef REQUIRE_PRIV
	if ( !check_previous_privilege(REQUIRE_PRIV) )
	{
	    error("Insufficient privs to open an outgoing socket.\n");
	}
#endif
	read_func = p2;
	close_func = p3;
	fdOwned = socket_create(0 /* MUD */,
				(: read_callback :),
				(: close_callback :));
	if ( fdOwned < 0 )
	    error("could not create socket: " + socket_error(fdOwned) + "\n");
	err = socket_connect(fdOwned, p1, "read_callback", "write_callback");
	if ( err < 0 )
	    error("could not listen to socket: " + socket_error(err) + "\n");
SKTLOG("create: SKT_STYLE_CONNECT_M",fdOwned);
SKTLOG("create: close_func",close_func);
	break;

    case SKT_STYLE_INT_ACQUIRE:
	read_func	= p1;
	close_func	= p2;
	break;
    }
}
