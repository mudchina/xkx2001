//Cracked by Roath
// 钱塘江畔
// Dong  11/03/1996.
// modified by aln 2 / 98

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", HIC"钱塘江畔"NOR);
    set("long", @LONG
钱塘江，每年八月十八是观潮的好日子。“八月十八潮，壮观天
下无”。潮水来时“远若素练横江，声如金鼓；近则亘如山岳，奋如
雷霆”，刹那间，漫江沸腾，泼涛万顷，潮高丈馀，万马奔腾，真有
“涛来势转雄，猎猎驾长风。雷震云霓里，山飞霜雪中”的壮丽气势。
西上月轮山便到了六和塔。
LONG	);

    set("exits", ([ /* sizeof() == 2 */ 
                   "east" : __DIR__"village",
                   "westup" : __DIR__"liuhe1", 
                   "north" : __DIR__"road77",  
                 ])
       );
	set("objects",([
                "/d/taishan/npc/jian-ke" : 1,
        ]));
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
