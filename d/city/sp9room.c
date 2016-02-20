//Cracked by Roath
// by ding@xkx
// modified by aln@xkx

inherit "/inherit/room/p9room";

void create()
{
        set("short", "牌九室");
        set("long", @LONG
这里是推牌九的地方，屋子中间摆着一张大台子。台子旁边立着个
小牌子 (paizi)。这里赌的是小牌九，每门两张牌，一翻一瞪眼。赌场
是庄家，赌客只能压（bet）闲家。
LONG );

        set("exits", ([
		"south" : "/d/city/duchang",
        ]));

        set("item_desc", ([
                "paizi" : 
"赌场抽税五厘，本赌场不备零散碎银。\n"
"牌九的玩法介绍可以看 help paigow.\n",
        ]));

        set("no_fight", "1");
        set("no_steal", "1");
        set("no_sleep_room", "1");

        set("cost", 0);
        setup();

}
