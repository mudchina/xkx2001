//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "石窟");
  set ("long", @LONG
这里的雕像多作於西魏时代。雕像面貌清瘦、眉目输朗、身体扁平、
眼小唇薄。有庄严慈详的佛像、清秀栝淡的菩萨、飘逸闲畅的飞天、威
猛粗纩的力士。
LONG);

  set("exits", ([ 
  "east" : __DIR__"dtongdao3",
]));

	set("cost", 2);
  setup();
  replace_program(ROOM);
}

