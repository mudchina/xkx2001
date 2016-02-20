//Cracked by Roath
// wanxing.c 万行庵
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "万行庵");
	set("long", @LONG
太子坪万行庵是古智禅师创建的。庵外满山长满莎椤花，花数芭合成一朵，
叶子包在花外，古人以其根坚难易而盛赞之，以喻洁身自好之高贵品质。由此
向南上便至金顶，下至接引殿。
LONG
	);
	set("exits", ([
		"southup" : __DIR__"jinding",
		"eastdown" : __DIR__"jieyin",
	]));

        set("objects", ([
                "/kungfu/class/emei/jingjia.c" :1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 1);
	setup();
}
