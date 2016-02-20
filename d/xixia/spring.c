//Cracked by Roath
// Room: /d/xixia/spring.c

inherit ROOM;

void create()
{
        set("short", "清新泉");
        set("long", @LONG
这是山中的一口清泉，位于林场北面的山坡上，周围是翠绿的松树，潺潺的
山泉水从泉眼缓缓地涌出，聚成一个小潭，小潭里的水又溢出流向山下，旁边一
条小路通向山下。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"kongdi",
  "northdown" : __DIR__"wangling",
]));
        set("cost", 3);
        set("outdoors", "xixia");
        set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

        setup();
        replace_program(ROOM);
}
