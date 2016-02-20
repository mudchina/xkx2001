//Cracked by Roath
// harbor.c
// by ALN@XKX

inherit F_CLEAN_UP;
inherit ROOM;

#define SHIP      "/clone/ship/seaboat"
#define SHIPS     "/clone/ship/"
#define SHIPNAME  "seaboat"
#include "/clone/ship/harbor.h";

void setup()
{
        object ship;
        string *files;

        ::setup();

        files = get_dir(SHIPS);
        for(int i = 0; i < sizeof(files); i++) {
                if( strsrch(files[i], SHIPNAME) == 0 ) {
                        files[i] = SHIPS + files[i];
                        if( ship = find_object(files[i]) )
                                ship->delete("yell_trigger");
               } 
        }
}

void init()
{
        add_action("do_yell", "yell");
}

int do_yell(string arg)
{
        object ship, harbor;
        string filename, *files;
        int i, tot;

        if( !arg || arg != "chuan" )
                return notify_fail("你大喊大叫的干什么？\n");

        files = get_dir(SHIPS);
        tot = 0;
        for(i = 0; i < sizeof(files); i++) {
                if( strsrch(files[i], SHIPNAME) == 0 ) tot++;
        }

        for(i = 1; i < tot + 1; i++) {
                if( this_object()->query("exits/enter" + i) )
                return notify_fail("别叫了，这么大眼睛没看见船？\n");
        }

        if( member_array(base_name(this_object()), wildharbors) != -1 )
                return notify_fail("这里是荒岛，哪里有船经过？\n");

        for(i = 1; i < tot + 1; i++) {
                if( !(ship = find_object(SHIP + i)) )
                ship = load_object(SHIP + i);

                if( !ship->query_temp("trigger") )  
                break;
        }

        if( i > tot )
                return notify_fail("你喊了半天，也没见一条船过来。\n");

        if( stringp(filename = ship->query("exits/out")) ) {
                if( !(harbor = find_object(filename)) )
                harbor = load_object(filename);

                message("vision", "渔船离了岸，驶向茫茫的大海。\n", harbor);
                harbor->delete("exits/enter" + i);
                ship->delete("exits/out");
        }

        ship->set_temp("trigger", 1);
        remove_call_out("do_ready");
        call_out("do_ready", 20, ship);

        this_object()->set("exits/enter" + i, base_name(ship));
        ship->set("exits/out", base_name(this_object()));

        if( (int)this_player()->query("age") < 16 )
                message_vision("$N使出吃奶的力气喊了一声：“船家”\n", this_player());
        else if( (int)this_player()->query("neili") > 500 )
                message_vision("$N吸了口气，一声“船家”，声音中正平和地远远传了出去。\n", this_player());
        else    message_vision("$N鼓足中气，长啸一声：“船家！”\n", this_player()); 

        message("vision", "一条渔船应声慢慢驶了过来，渔夫将一块踏脚板搭在沙滩上。\n", this_object());

        return 1;
}

int valid_leave(object me, string dir)
{
        if( strsrch(dir, "enter") == 0 && !this_object()->query("navigate/locx") ) {
                switch (MONEY_D->player_pay(this_player(), 1000)) {
                case 0:
                        return notify_fail("穷光蛋，一边呆着去！\n");
                case 2:
                        return notify_fail("您的零钱不够了，银票又没人找得开。\n");
                default:
                        remove_call_out("do_ready");
                        call_out("do_ready", 10);
                        break;
                }
        }

        return ::valid_leave(me, dir);
}

void do_ready(object ship)
{
        object *inv, carbin;
        string filename, argg;
        int i, num;

        if( !stringp(filename = ship->query("exits/out")) )  return;
        if( filename != base_name(this_object()) ) return;

        ship->delete_temp("trigger");
        ship->delete("exits/out");

        inv = all_inventory(ship);
        for(i = 0; i < sizeof(inv); i++) {
                if( userp(inv[i]) ) {
                        inv[i]->move(this_object());
                        message_vision("只听「砰！」的一声，$N被船夫踢下船来狼狈不堪。\n", inv[i]);
                }
        }

        if( stringp(filename = ship->query("exits/down")) ) {
        if( carbin = find_object(filename) ) {
        inv = all_inventory(carbin);
        for(i = 0; i < sizeof(inv); i++) {
                if( userp(inv[i]) ) {
                        inv[i]->move(this_object());
                        message_vision("只听「砰！」的一声，$N被船夫踢下船来狼狈不堪。\n", inv[i]);
                }
        }
        }
        }

        message("vision", "船夫们大喝一声“开船”，于是船便离了岸。\n", ship);

        filename = base_name(ship);
        if( sscanf(filename, "%s%d", argg, num) == 2 )
        this_object()->delete("exits/enter" + num);
        message("vision", "渔船离了岸，驶向茫茫的大海。\n", this_object());
}
