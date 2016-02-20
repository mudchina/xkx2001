//Cracked by Roath
// group bwdh/wizroom
// Apache 09/29/98

inherit ROOM;

string look_note();

void create() {
    set("short", "试剑山庄凌霄阁");
    set("long", @LONG
这里是试剑山庄的主人居住的地方。从这里也可以俯瞰
整个试剑山庄。墙上挂着一幅字(note)，很引人注意。不过
屋里的东西倒是更让人吃惊。
LONG
    );
    set("exits", ([
        "square"  : __DIR__"square",
        //"skantai" : __DIR__"kantai_s",
        //"nkantai" : __DIR__"kantai_n",
        "eastxf"  : __DIR__"east_xiangfang",
        "westxf"  : __DIR__"west_xiangfang",
        "center"  : __DIR__"room_28",
        //"dc"  : __DIR__"gamble_room",
    ]));
    set("objects", ([
        __DIR__"obj/casino" : 1,
//        __DIR__"obj/control"     : 1,
        __DIR__"obj/microphone"  : 1,
    ]));
    set("item_desc", ([
        "note" : (: look_note :),
    ]));
    setup();
}

void init() {
    object me = this_player();
    if ( !wizardp(me) )
        me->move("/d/death/blkbot");
}

string look_note() {
    string msg;

    msg = "
一场比武的操作程序：
  1. assign group entrance (assign n east/west)
<after they all enter>
  2. duet init (need dispatch camera team here, so be sure all ppl entered)
  3. casino set ratio (casino east/west n)
  4. casino bet
  5. casino stop
  6. duet start
  7. judge east/west/tie
  8. casino east/west/ 0 (set winner)
  9. casino pay
 10. casino stop
其他参考相关命令。\n";

    return msg;
}