//Cracked by Roath
// Room: pubu.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "长白瀑布");
	set("long", @LONG
传过一道石壁，眼前赫然出现一条飞泻而下的瀑布。这是天池的水从北
面缺口闼门流出后，夹流在天豁峰和龙门峰之间，行至此处，陡然从悬崖峭
壁上跌水直泻，犹如一条白练从天而降，两条玉龙般的水柱冲向幽深谷底，
溅起几丈高的白浪，恰似云倾雪翻，钟鼓雷鸣一般。由于水势湍急且此地潮
暖，因此并不结冰。
LONG	);
	set("exits", ([ 
              "southwest" : __DIR__"banlp",
              "northup" : __DIR__"tieby",
        ]));
	
        set("outdoors", "changbai");
        set("cost", 3);

        set("count", random(3)+1);

	setup();
}
