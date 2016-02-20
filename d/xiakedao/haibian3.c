//Cracked by Roath
// Dong 1/9/98
// modifiedy by aln 5 / 98
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "海边");
    	set("long", @LONG
一望无际的大海泛着银光，白日间潮声澎湃，到了夜晚，明月共
潮而生，端的是一片迤俪风光。岸边上是一排高高的椰子树，树上还
挂着几只椰子。一阵海风吹过，椰子树随风摇摆着，椰子好像就要掉
下来似的。
LONG
    	);

    	set("exits", ([
		       "north" : __DIR__"haibian2",
		       "southeast" : __DIR__"shatan",
		       ]));
    	set("outdoors", "xiakedao");
	set("objects", ([ 
			 __DIR__"obj/yezitree" : 1, 
			 ]));

    	setup();
}


