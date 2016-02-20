//Cracked by Roath
// changle/clbajiaoting.c
// by aln 2 / 98
// xQin 8/00

inherit ROOM;

void create()
{
        set("short", "八角亭");
        set("long", @LONG
这是花园中一个小巧的亭子，供赏花时休息之用。亭中石桌石凳
俱全，石桌上还摆放着几盘点心。院中花卉暗香浮动。几个假山做得
甚是别致。
LONG );

        set("exits", ([
		"north" : __DIR__"clhuayuan",
		"west" :  __DIR__"clzoulang1",
        ]));
        set("objects", ([
                "/kungfu/class/misc/dingdang.c" : 1,
                        ]));
                        
        set("cost", 0);

        setup();

        replace_program(ROOM);
}
