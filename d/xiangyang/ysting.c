//Cracked by Roath
// Room: /d/xiangyang/ysting.c

inherit ROOM;

void create()
{
	set("short", "议事厅");
	set("long", @LONG
厅上见居中一张太师椅，上铺虎皮，一人正悠闲地倚於椅上，两旁各有
小妾正为他槌胸揉背。虎皮椅旁有两座大理石屏风，都有五六丈高，石上山水
木碑，便如画出来的一般。这本是安抚使审理军政民政及监察事务所在，但
没人之时，便成了暂且神游物外的安乐窝。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xiansi",
  "south" : __DIR__"huating",
]));
        set("objects", ([
               __DIR__"npc/wende" : 1, 
        ]));
	setup();
	replace_program(ROOM);
}
