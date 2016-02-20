//Cracked by Roath
// xiakedao/shanlu1.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "山路");
        set("long", @LONG
走在青石铺成的小路上，脚步十分轻捷。两旁都是密林，枝叶遮
天蔽日，阴沉沉的很不舒服。林中鸟雀叽喳，与呼呼的风声混成一片。
LONG );

      set("exits", ([
      	"south" : __DIR__"ybting",
		"north" : __DIR__"shanlu2",
		"eastup"  : __DIR__"shanlu3",
      ]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	set("objects", ([ 
	    __DIR__ + "npc/dahan" : 1,
          "/d/city/obj/branch1" : 1,
          "/d/city/obj/branch2" : 1,
      ]));

	setup();
}
