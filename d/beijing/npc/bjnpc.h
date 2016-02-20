//Cracked by Roath
// bjnpc.h 
// by Ssy
// will random walk only in Beijing city.

int random_walk();
string startroom="/d/beijing/tianqiao";
mapping nondirs = ([
        "/d/beijing/yonganmen": "south",
]);

int random_walk()
{
        mapping exits, doors;
        string *dirs, dir, last_room, this_room;
        object here = environment();

        if( strsrch(base_name(here), "/d/beijing/") != 0 ) {
                message("vision", name() + "急急忙忙地离开了。\n",
                environment(), this_object());
                move(startroom);
                message("vision", name() + "走了过来。\n",
                environment(), this_object());
        }

        if( !objectp(environment()) 
        || !mapp(exits = environment()->query("exits")) 
        || query("jingli") < query("max_jingli") / 2 ) return 0;
        dirs = keys(exits);

        if( sizeof(dirs) == 0 ) return 0;

        this_room = base_name(here);
        if( member_array(this_room, keys(nondirs)) != -1 ) {
                dirs -= ({nondirs[this_room]});
        }

        dir = dirs[random(sizeof(dirs))];
        command("go " + dir);

        return 1;
}
