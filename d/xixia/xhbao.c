//Cracked by Roath
// Room: /d/xixia/xhbao.c

inherit FERRY;

void create()
{
        set("short", "宣和堡");
        set("long", @LONG
这里就是西北小镇宣和堡，南面是黄河，西面是沙漠，只有这里有一片不大
的绿洲，住户们都是从关内迁移过来的，大多以经营手工艺品为生, 这里的手织
羊毛挂毯颇有名气。每逢初一、十五，附近的百姓都来到这摆渡过河到关内去赶
集。河岸边熙熙攘攘，人们都在争着叫(yell)船过河。
LONG
        );
        set("cost", 2);
        set("outdoors", "xixia");
        set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"mszhou",
]));

        set("name", "江");
        set("boat", __DIR__"duchuan");
        set("opposite", __DIR__"oldwall");

        setup();
}
