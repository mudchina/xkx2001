//Cracked by Roath
// 宝石山
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "宝石山");
   set("long", @LONG
宝石山不是很高，山上多奇峰怪石。山路旁有一座亭子“来凤亭”，
亭前有块卵形大石，临空搁置在山巅，叫落星石，又称寿星石。再往
北上就到了保淑塔，往南下便回到大道了。
LONG  );

   set("exits", ([ /* sizeof() == 2 */ 
                  "northup" : __DIR__"baoshi2", 
                  "southdown" : __DIR__"road12", 
                ])
       );
	set("objects", ([
            "/d/city/obj/stone" : 2,
        ]));

	set("cost", 4);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
