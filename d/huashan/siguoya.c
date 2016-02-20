//Cracked by Roath
// 华山思过崖
// qfy 26/6/1996 

inherit ROOM;

void create()
{
        set("short", "思过崖");
	set("long", @LONG
这是华山的思过崖。危崖上有个山洞，是华山派历代弟子犯规后囚禁
受罚之所。崖上光秃秃的寸草不生，更无一株树木。这危崖自来自来相传
是玉女发钗上的一颗珍珠，当年华山派的祖师以此危崖为惩罚弟子之所，
主要是便此一处无草无木，无虫无鸟，受罚的弟子在面壁思过之时，不致
为外物所扰，心有旁鹜。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  	"southdown" : __DIR__"shanlu2",
  	"enter" : __DIR__"shandong",
]));

	set("cost", 3);
        setup();
}

void init()
{
	add_action("do_say", "say");
}	

void do_say(string arg)
{  
	string name;
	object me = this_player();
	
	if( !arg || arg=="" ) return 0;
	
	if( arg == "风清扬" && !me->query_temp("marks/风") && random(30) == 5 ) {
	  message_vision("突然$N背后传来一声长叹：“难得世上居然还有人知道风某的名字。”\n", me);
          message_vision("$N回过头来，见山洞口站着一个白须青袍老者，神气抑郁，脸如金纸。\n", me);
          me->set_temp("marks/风", 1);
	  if ( me->query("shen") >= 10000 ) {      
	        message("vision","风清扬对"+me->name()+"低声地说了几句话。说罢便飘然下山。\n", 
	                environment(me), ({me})); 	
		write( "风清扬低声地说道：“当年独孤求败前辈以一柄玄铁重剑称雄江湖，\n");
		write( "号称「剑魔」，走遍天下欲觅一对手而不获，为求一败而不得，一生\n");
		write( "寂寂。最终与一神雕归隐，埋剑「剑冢」。呜呼！群雄束手，长剑空\n");
		write( "利，不亦悲夫！据闻「剑冢」的所在地是位于泰山试心石后，心存诚\n");
		write( "意，入口自现。至于到底如何心存诚意，则非我所知。希望你能寻得\n");
		write( "宝剑，造福武林。\n");
		write( "风清扬说罢，便飘然下山。\n");
          }
          else {	
          	message_vision( "风清扬说罢，又对$N一声长叹，便飘然下山离去。\n", me );
          }	
	}
	
	if( arg == "风清扬" && me->query_temp("marks/风") ) {
      write( "清枫突然跳了出来说道：“不是见过风清扬了吗？还不快去找玄铁剑？”\n");
	}  
}		 
