//Cracked by Roath
// 海盗窝
// Ssy

inherit __DIR__"no_pk_room";
string* npcs = ({
        "haidao_s",
        "haidao_o",
        "haidao_w",
});

void create()
{
        int i = random(sizeof(npcs));
        int j = random(sizeof(npcs));

    	set("short", "海盗窝");
    	set("long", @LONG
这间草棚破破烂烂，里面只有几张小床和一点干粮，床上还躺了
几个人。
LONG
    	);

    	set("exits", ([
		       "out" : __DIR__"haidaowo",
		       ]));
        set("objects", ([ 
			 __DIR__"npc/"+npcs[i] : 1,
                         __DIR__"npc/"+npcs[j] : 1,
			 ]));

    	setup();
}


