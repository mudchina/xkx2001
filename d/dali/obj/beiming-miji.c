//Cracked by Kafei
// beiming-miji.c 北冥秘籍
// AceP

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}

void create()
{
  set_name("北冥秘籍", ({"beiming miji", "beiming", "miji"}));
  set_weight(500);
  if (clonep())
  set_default_object(__FILE__);
  else {
	  set("unit", "本");
	  set("long", "这是一卷武林中极为密秘的《北冥秘籍》，记录着早已失传的逍遥派的绝密武功。\n");
	  set("value", 1000000000);
	  set("material", "paper");
	  set("no_drop", "这样东西不能离开你。\n");
	  set("no_get", "这样东西不能离开那儿。\n");
  }
}

int do_du(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	
	int i = me->query_skill("beiming-shengong", 1);

	if (!(arg=="beiming miji" || arg=="beiming" || arg=="miji" || arg=="miji2"
		|| arg=="beiming miji2" || arg=="lingbo-weibu" || arg=="weibu"))
		return 0;

	if (where->query("pigging")){
		write("你还是专心拱猪吧！\n");
      return 1; }

	if (me->is_busy()) {
		write("你现在正忙着呢。\n");
		return 1; }

	if (me->is_fighting() ) {
		write("你无法在战斗中专心下来研读新知！\n");
		return 1; }

	if (!id("beiming miji")) {	
		write("你要读什么？\n");
		return 1; }

	if (!me->query_skill("literate", 1) ){
		write("你是个文盲，先学点文化(literate)吧。\n");
		return 1; }
	
	message("vision", me->name() + "拿出一个帛卷学习了一会儿。\n", environment(me), me);
	
	if ((arg=="beiming miji2"
		|| arg=="weibu"
		|| arg=="miji2"
		|| arg=="lingbo-weibu")
		&& me->query_skill("beiming-shengong",1))
	{
		if (me->query("jing") < 25 ) {
			write("你现在过于疲倦，无法专心下来研读新知。\n");
			return 1; }

		if (me->query("per")<20) {
			write("你读了半天凌波微步，可总也领悟不了那潇洒自如的步法该怎么走。\n");
			return 1; }

		if (me->query_skill("literate", 1) < (me->query_skill("lingbo-weibu")-30)) {
			write("你的读书写字水平不够，没法领会北冥密籍了。\n");
			return 1; }

		if (me->query_skill("lingbo-weibu",1) > 400) {
			write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
			return 1; }

		me->receive_damage("jing", 25);
		me->improve_skill("lingbo-weibu", (int)me->query_skill("literate", 1)/5+1);
		write("你研读《北冥秘籍》，凌波微步有所进步。\n");
		return 1; }

	if (me->query("gender") == "无性") {
		write("嘿嘿，您学不了北冥神功啦。\n");
		return 1; }

	if (me->query("class") == "bonze") {
		write("罪过啊，罪过。和尚怎么能读北冥密籍？！？\n");
		return 1; }
	
	if ((int)me->query_skill("force", 1) < 10
		|| (int)me->query_skill("force", 1)< (i-30)) {
		write("你的基本内功火候不足，无法学习北冥神功。\n");
		return 1; }

	if ((int)me->query_skill("literate", 1) < (i-30)) {
		write("你的读书写字水平不够，没法领会北冥密籍了。\n");
		return 1; }

	if (me->query_skill("beiming-shengong",1) > 99) {
		if ((int)me->query("jing") < 40 ) {
			write("你现在过于疲倦，无法专心下来研读新知。\n");
			return 1; 
		}
	}
	else {
		if ((int)me->query("jing") < 25 ) {
			write("你现在过于疲倦，无法专心下来研读新知。\n");
			return 1; }
	}

	if ((int)me->query("combat_exp") < (int)i*i*i/10 ) {
		write("你的实战经验不足，北冥神功无法再提高了。\n");
		return 1; }

	if (me->query_skill("beiming-shengong", 1) > 400){
		write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
		return 1; }

	if (!me->query_skill("beiming-shengong", 1))
	{
		if (me->query_skill("hunyuan-yiqi",1)
			|| me->query_skill("huntian-qigong",1) 
			|| me->query_skill("taiji-shengong",1)
			|| me->query_skill("zixia-shengong",1)
			|| me->query_skill("linji-zhuang",1)
			|| me->query_skill("hamagong",1)
			|| me->query_skill("huagong-dafa",1)
			|| me->query_skill("bitao-xuangong",1)
			|| me->query_skill("yunu-xinjing",1)
			|| me->query_skill("wudu-xinfa",1)
			|| me->query_skill("longxiang-banruo",1)
			|| me->query_skill("xiantian-gong",1)
			|| me->query_skill("dulong-dafa",1)
			|| me->query_skill("kurong-changong",1))
		{
		write("你不先散了别派内功心法，没法开始学习北冥神功。\n");
		return 1; }

		me->set_skill("beiming-shengong", 0);

write("                   《北冥秘籍》\n\n"
"    帛卷的第一行写的是：“北冥神功”。\n"
"长卷上源源皆是裸女图像，或立或卧，或现前胸，或现后背，一共三十六张图像，\n"
"每幅像均有颜色细线，注明穴道部位及练功法诀等等，是修炼北冥神功的法门。\n\n"
"    帛卷的尽头题着“凌波微步”。\n"
"后面绘的是无数足印，注明“归妹”，“无妄”等尽是“易经”中的方位。只见足\n"
"印密密麻麻，不知道有几千百个，自一个足印到另一个足印均有绿线连接，线上绘\n"
"有箭头，是一套繁复的轻功步法。\n"
"最后一行写道：猝遇强敌，以此保身，更积内力，再取敌命。\n\n\n"
"学习北冥神功注意事项：\n"
"一. 要学习北冥神功必先放弃别派内功心法。\n\n"
"二. 北冥神功威力很大，当敌人以加力击中你，将会自行将内力送入你体内。\n"
"    而且练到一定级别之后，可以在战斗中主动吸取敌人的内力。\n\n"
"三. 《北冥秘籍》不可送人，出售，丢弃，捡拾，唯一的获取方法是你到指定\n"
"    的地方用特殊命令取得。\n\n"
"四. 北冥神功无师可拜，也不能通过自己锻炼来长进，只有研习《北冥秘籍》\n"
"    才能提高。\n\n"
"五. 北冥神功对基本功的要求很苛刻，无法超过基本内功三十级以上，如果读\n"
"    书写字低于北冥神功三十级，将无法读懂《北冥秘籍》。\n\n"
"六. 北冥神功除了吸取内力外，还有一些特别用途，请你细心体会吧。\n\n"
"         早日精通北冥神功，你必可成为武林第一高手！\n"); }

	if (me->query_skill("beiming-shengong", 1)<100)
		me->receive_damage("jing", 25, "心力绞瘁死了");
	else me->receive_damage("jing", 40, "心力绞瘁死了");

	me->improve_skill("beiming-shengong", me->query_skill("literate", 1)/5+1);
	write("你研读《北冥秘籍》，北冥神功有所进步。\n");
	return 1;
}
