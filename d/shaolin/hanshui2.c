//Cracked by Roath
// Room: /d/shaolin/hanshui2.c
// Date: YZC 96/01/19
// modified by aln 4 / 98
//modified by xiaojian Aug.17,2000


inherit FERRY;

void create()
{
        set("short", "汉水北岸");
        set("long", @LONG
汉水北岸也是相当热闹，自北岸渡口往北，一条笔直的官道
直通南阳。此地民风淳朴，路旁夹柳成阴，酒厮林立，且都有一
面大大的「酒」旗迎风飘扬，蔚为壮观。也有不少小贩沿路叫买，
语多难辨，却也令人盛情难却。
LONG
        );

        set("exits", ([
        "north" : __DIR__"nanyang",
	    "west" : __DIR__"riverbank",
        ]));

        set("item_desc", ([
        "river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",

    ]));

        set("outdoors", "shaolin");
        //set("resource/water", 1);
        set("outdoors", "shaolin");
        set("cost", 1);

        set("name", "江");
        set("boat", __DIR__"duchuan");
        set("opposite", __DIR__"hanshui1");

        setup();
}
