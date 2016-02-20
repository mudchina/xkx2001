inherit ROOM;

string look_note();

void create() {
    set("short", "秘密交流室");
    set("long", @LONG
这里是供玩家与巫师秘密交流的地方。玩家可以在这里向巫师报告ＢＵＧ，
提供建议，进行广泛的讨论。南面的墙上贴着告示（note）。
LONG
    );

    set("exits", ([
    	"east" : "/d/wizard/guest_room" , 
    ]));

    set("item_desc",([
        "note"        :    (: look_note :),
    ]));


    set("valid_startroom",1);
    set("no_steal", 1);
    set("no_sleep_room", 1);
	set("cost", 0);
	set("no_fight", 1);
    setup();
   	"/clone/board/proom_b"->foo();
}

string look_note() {
    return "
玩家在这里贴的文章，只能由本玩家和巫师阅读。
玩家和巫师可以用re xx  (xx为文章篇目) 命令来
张贴对以前文章的回应。回应文章也只能被第一篇
文章的作者和巫师阅读。其它留言板命令不变。

乱灌水者打入十八层地狱。
\n";
}

void init() {
	add_action("do_null",  "exercise");
	add_action("do_null",  "dazuo");
	add_action("do_null",  "respirate");
	add_action("do_null",  "tuna");
	add_action("do_null",  "practice");
	add_action("do_null",  "lian");
	add_action("do_null",  "study");
	add_action("do_null",  "du");
}

int do_null(string arg) {
        object me = this_player();
        tell_object(me, "休息，休息，休息一会儿吧。\n");
        return 1;
}
