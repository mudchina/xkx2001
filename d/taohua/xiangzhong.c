//Cracked by Roath
//kane

inherit ROOM;

void create()
{
	set("short", "香冢");
	set("long", @LONG
一转出桃林，忽然出现了一片白色花丛，重重叠叠，宛似一座白花堆成的小湖。
白花之中有一块东西高高隆起，定睛一看，原来是一座石坟，坟前墓碑(mubei)上刻着
“桃花岛女主冯氏埋香之冢”十一个大字。墓前四时鲜花常开，每本都是黄药师精选
的天下名种，奇花异卉，各自分香吐艳。
LONG
	);
	set("item_desc", ([
                "mubei" : "墓碑背面刻着两行歪歪斜斜的小字：且夫天地为炉兮，造化为工！阴阳为炭兮，\n"
			  "万物为铜！\n"
			  "墓碑左面，右面，正面似乎特别光滑。\n",
        ]));
        
	set("exits", ([
                "east" : __DIR__"taolin",
        ]));
      	
	
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
//	replace_program(ROOM);
}

void init()
{
  add_action("do_push","push");
}

int do_push(string arg)
{
  	object me = this_player();

  	if (!arg) return 0;

        if ( (int)me->query_str() < 28 ) {
                return notify_fail("你没那么大力气搬动墓碑。\n");
        }  
  	
	if (arg == "left") {
    	add_temp("left",1);
    	write("墓碑摇晃了一阵，再不见动静...\n");
  	}

  	if ((arg == "right") && ((int)query_temp("left")==3)) {
    	add_temp("right",1);
    	write("墓碑摇晃了一阵，再不见动静...\n");
  	}

  	if ((arg == "front") && ((int)query_temp("right")==3) && ((int)query_temp("left")==3)) {
    	write("墓碑摇晃了一阵，缓缓向后倒去，露出一个入口。\n");
    	set("exits/enter", __DIR__"didao");
    	remove_call_out("close_door");
    	call_out("close_door",15,me);
  	}

  	return 1;
}

void close_door()
{

  if (((int)query_temp("left")!=3) || ((int)query_temp("right")!=3)) return;

  	delete("exits/enter");
  	delete_temp("left");
  	delete_temp("right");
}
