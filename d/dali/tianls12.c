//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "斋房");
        set("long", @LONG
这里是寺内用餐和方丈宴请贵客的地方。这里曾有几回土蕃黄教
的国师、天竺神僧，和少林长老拜访讲经，方丈就在此为他们揭尘。
斋房的厨师可也是了不得的人物，其技艺绝不输于大理皇宫。能吃到
他们准备的素斋，便是天赐的口福。室内一尘不染，竹编的椅子和石
雕的长桌亦是一奇。
LONG
        );
        set("exits", ([
		"south" : __DIR__"tianls7.c",
		]));
    setup();
}

      