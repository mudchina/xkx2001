//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "牟尼堂");
        set("long", @LONG
这是一间狭室，禅房内古璞归真，日常用具不多，不过有见识的人可以看出，
东西虽不见奢侈，却也都不是易得之物。禅房里面四散着坐了六个老僧。
LONG );

        set("cost", 1);
       set("objects", ([
"/kungfu/class/dali/benchen" : 1,
"/kungfu/class/dali/benyin" : 1,
"/kungfu/class/dali/benguan" : 1,
"/kungfu/class/dali/benxiang" : 1,
"/kungfu/class/dali/bencan" : 1,
"/kungfu/class/dali/kurong" : 1,
              ]));
        set("exits", ([
		"out" : __DIR__"tianls10.c",
		]));
    setup();
}











