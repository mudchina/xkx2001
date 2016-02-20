//Cracked by Roath
// 飞来峰
// Dong  11/03/1996.
// modified by aln 2 / 98

#include <room.h>
#include <ansi.h>

#define BANGZHU "/d/huanghe/npc/bangzhu"

inherit ROOM;

void create()
{       set("short", "飞来峰");        
        set("long", @LONG
飞来峰又名灵鹫峰。延着盘山小道往上走，只见溪盘岩石壁间雕
着一尊袒腹露胸，喜笑自若的弭勒佛。旁边是一座气魄胸伟的多闻天
王。北边是下山的路。小路往上延伸向东西两边。
LONG);

        set("objects",([
                BANGZHU : 1,
        ]));

        set("exits", ([ /* sizeof() == 3 */ 
                "eastup" : __DIR__"feilai4", 
                "north" : __DIR__"road34", 			
                "westup" : __DIR__"feilai1",  			
        ]));

	set("cost", 4);
        set("outdoors", "hangzhou");

        setup();

        replace_program(ROOM);
}
