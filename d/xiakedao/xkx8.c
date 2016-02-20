//Cracked by Roath
// xiakedao/xkx8.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 2;

void create()
{
        set("short", "石室");
        set("long", @LONG
石洞正中，一位白眉僧人和一位青袍之人正比试武功。一对男女
在旁边并肩奔行，趋退之际，步法配合甚是和谐。另有一人神色不屑
地站在墙角，边指点石壁(wall)，边指摘众人的招式。
LONG );

      set("exits", ([
		"east" : __DIR__"xiakexing2",
      ]));
	set("item_desc",([
	    "wall" : "
墙的正上方刻着「深藏身与名」几个大字。字的下方刻的是一个脍炙
人口的故事：范蠡与西施功成身退，泛舟湖上。只见图中美女星目含
情，旁边是范大夫微笑不语。舟下的水纹荡漾，与远方天色连成一体。
\n",
	]));

	set("indoors", "xiakedao" );
	set("cost", 0);
      set("objects",([
            __DIR__+"npc/huang.c" : 1,
            __DIR__+"npc/yideng.c" : 1,
          ]));
	setup();
}
void init()
{
        ::init();
	add_action("do_study", "study");
}
#include "/d/xiakedao/xkx.h"
