//Cracked by Roath
// road: /zhongnan/taiyici3.c
// by sdong 08/98

#include <ansi.h>
inherit ROOM;

int do_climb(string arg);
int do_swim(string arg);

int do_practice(string arg);
int do_exercise(string arg);

void create()
{
		  set("short",HIC"̫�ҳ�"NOR);
		  set("long",@LONG
�����ں�ˮ�ֻ���ú�ˮ����͸�ǡ��������ܸ߷廷�У�����̲�������
ɽ��ˮӰ���羰���ˡ�����ԭ����̫�ҳص�������̫�۵Ļ����������(climb)
�ϰ���ԶԶ��ȥ�����ߵİ�����һ��С·ͨ������ɽ���塣�벻����(swim)��
ȥ����
LONG);


		  set("resource/water", 1);


		  set("no_clean_up", 0);

	  set("cost",4);
	  set("outdoors", "zhongnan");
	  setup();
}

void init()
{
	add_action("do_swim", "swim");
	add_action("do_climb", "climb");
	add_action("do_exercise",  "exercise");
	add_action("do_exercise",  "dazuo");
	add_action("do_exercise",  "respirate");
	add_action("do_exercise",  "tuna");
	add_action("do_practice",  "practice");
	add_action("do_practice",  "lian");
	add_action("do_study",  "study");
	add_action("do_study",  "du");
}

int do_exercise(string arg)
{
		  object me = this_player();
		  tell_object(me, "��ô���ˮ���ȶ��Ȳ����ף���ô��������\n");
		  return 1;
}

int do_practice(string arg)
{
		  object me = this_player();
		  tell_object(me, "��ô���ˮ���ȶ��Ȳ����ף���ô��������\n");
		  return 1;
}

int do_study(string arg)
{
		  object me = this_player();
		  tell_object(me, "��ô���ˮ���ȶ��Ȳ����ף���ô���鰡��\n");
		  return 1;
}



int do_swim(string arg)
{
	object me = this_player();
	int cost;

	if(me->is_busy())
		return notify_fail("�㻹��æ���ء�\n");
	cost = (200-me->query_skill("swimming",1))/10;
	if ( cost<3 )cost = 3;
	me->add("jingli",-cost);
	me->improve_skill( "swimming",random( me->query("con",1)/2 ) );
	me->start_busy(random(3));

	if (arg == "west")
	{
		return notify_fail("���Ѿ��������ˡ�\n");
	}
	else if (arg == "east")
	{
		message_vision( HIY"\n$N��̫�ҳ��л��˻�ˮ����������������\n"NOR, me);
		me->move("/d/zhongnan/taiyici2");
		message_vision( HIY"\n$N���˹�����\n"NOR, me);
		return 1;
	}

	message_vision( HIY"\n$N��̫�ҳ��л��˻�ˮ����������������\n"NOR, me);
	return 1;
}

int do_climb(string arg)
{
	object me = this_player();

	if(me->is_busy())
		return notify_fail("�㻹��æ���ء�\n");
	if(arg == "up" || arg=="west" )
	{
		message_vision( HIY"\n$N��̫�ҳ���������������ȥ��\n"NOR, me);
		me->move("/d/zhongnan/hubing");
		message_vision( HIY"\n$N��̫�ҳ�������������\n"NOR, me);
		return 1;
	}

	return notify_fail("�Ǹ�����û������\n");
}