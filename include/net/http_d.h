//Cracked by Roath
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
 * Config file for LIMA HTTP server
 * 01-05-96 Cowl
 *
 */
#ifndef __HTTP_D_H__
#define __HTTP_D_H__

#define PORT_HTTP 80
#define WIZ_DIR "/u/"
// this is the directory that the http server will use as it's root
#define HTTP_ROOT 		"/WWW"

// this is the directory inside a wizard's home directory that will be
// checked for homepages etc..
#define HTTP_USER_HOME 		"WWW"

// this is the default page if the URL given is a directory
#define DEFAULT_PAGE 		"index.html"

// this is where the server will look for secure gateways (eg, webed)
// The URL for these is http://machine:port/scgi/blah.c
#define SECURE_CGI_DIR 	"/secure/cgi"

// This is the how much info is passed to the socket object at a time.
#define HTTP_BLOCK_SIZE 1024

#endif
