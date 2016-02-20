//Cracked by Roath
// /inherit/room/an.c
// cleansword 2 / 96
// by aln 4 / 98

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();

void setup()
{
        object room;

        ::setup();

        if( room = find_object(this_object()->query("boat")) )
        room->delete("yell_trigger");
}

void init()
{
        add_action("do_yell", "yell");
}

int do_yell(string arg)
{
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg == "boat" ) arg = "船家";

        if( (int)this_player()->query("age") < 16 )
                message_vision("$N使出吃奶的力气喊了一声：“" + 
                        arg + "”\n", this_player());
        else if( (int)this_player()->query("neili") > 500 )
                message_vision("$N吸了口气，一声“" + arg + 
                        "”，声音中正平和地远远传"
                        "了出去。\n", this_player());
        else    message_vision("$N鼓足中气，长啸一声：“" + arg + 
                        "！”\n", this_player());

        if( arg == "船家") {
                check_trigger();
                return 1;
        } else  message_vision(this_object()->query("name") + "面上远远传来一阵回声：“" + arg +
                        "～～～”\n", this_player());

        return 1;
}

void check_trigger()
{
        object room;
        string myboat;

        if( this_object()->query("exits/enter") ) {
                message("vision", "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n",
                        this_object());
                return;
        }

        if( !(room = find_object(myboat = this_object()->query("boat"))) )
                room = load_object(myboat);

        if( !(room = find_object(myboat)) ) {
                message("vision", "ERROR: boat not found\n", this_object() );
                return;
        }

        if( room->query("yell_trigger") ) {
                message("vision", "只听得" + this_object()->query("name") + "面上隐隐传来：“别急嘛，"
                        "这儿正忙着呐……”\n", this_object() );
                return;
        }

        room->set("yell_trigger", 1);
        this_object()->set("exits/enter", myboat);
        room->set("exits/out", base_name(this_object()));

        message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚"
                "板搭上堤岸，以便乘客\n上下。\n", this_object() );
        message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上"
                "的阶梯。\n", room);

        remove_call_out("on_board");
        call_out("on_board", 15);
}

void on_board()
{
        object room;

        if( !this_object()->query("exits/enter") ) 
                return;

        message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向" + this_object()->query("name") + "心驶去。\n", this_object() );

        if( room = find_object(this_object()->query("boat")) ) {
                room->delete("exits/out");
                message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
                        "竹篙一点，扁舟向\n" + this_object()->query("name") + "心驶去。\n", room );
        }

        this_object()->delete("exits/enter");

        remove_call_out("arrive");
        call_out("arrive", 20);
}

void arrive()
{
        object room;
        string myboat = this_object()->query("boat");
        string myopp = this_object()->query("opposite");

        if( room = find_object(myboat) ) {
                room->set("exits/out", myopp);
                message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板"
                        "搭上堤岸。\n", room );
        }

/*
        if( !(room = find_object(myopp)) )
                room = load_object(myopp);

        if( room = find_object(myopp) ) {
                room->set("exits/enter", myboat);
                message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚"
                        "板搭上堤岸，以便乘客\n上下。\n", room);
        }
*/       

        remove_call_out("close_passage");
        call_out("close_passage", 20);
}

void close_passage()
{
        object room;

        if( room = find_object(this_object()->query("boat")) ) {
                room->delete("exits/out");
                message("vision", "艄公把踏脚板收起来，把扁舟驶向" + this_object()->query("name") + "心。\n", room);
                room->delete("yell_trigger");
        }

/*
        if( room = find_object(this_object()->query("opposite")) ) {
                room->delete("exits/enter");
                message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向" + this_object()->query("name") + "心驶去。\n", room);
        }
*/
}
