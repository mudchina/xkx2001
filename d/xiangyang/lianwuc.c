//Cracked by Roath
// Room: /d/xiangyang/lianwuc.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这是兵营中间的一块大空地，各营的兵士们分别列队在此布阵操练。一队队
的官兵或在主将的指挥下排练阵形，或整齐的习练器刃、或二人各自竞技。北面
罗列着一些稻草人，那是给士兵们射箭抡刀投枪设的靶子。不时有武将在一旁巡
视纠正。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("coordinates", ([ "x" : -2, "y" : -2 ]) );
	set("exits", ([ /* sizeof() == 5 */
  "east" : __DIR__"bingying",
  "north" : __DIR__"bingy2",
  "enter" : __DIR__"bingqiku",
  "west" : __DIR__"xiaoshi",
  "south" : __DIR__"bingyi",
]));
        set("objects", ([
               __DIR__"npc/wangjian" : 1, 
        ]));
	setup();
	replace_program(ROOM);
}
