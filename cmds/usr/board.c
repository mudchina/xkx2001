// Change by Server
// board.c
// by Marz@XKX 11/09/96
// modified by Jay 6/2/97

inherit F_CLEAN_UP;

int main(object me)
{
	return notify_fail("请用help board查看留言版使用方法。\n");
}

int help()
{
	write(@HELP

客店及各个门派的留言版是玩家交留经验、心得的重要地方，
巫师也通过留言版发布ＭＵＤ的各种改动，因此一定要及时
查看。留言版指令在有留言版（Ｂｏａｒｄ，Ｒｅｐｏｒｔ
等）的地方才有效。

	list 			: 查看该留言版目录
	read <＃>		: 阅读第＃号留言
	post <title>		: 如果你也想来写几句…
	discard <＃>		: 删除第＃号留言。可是你只能删你自己留的


HELP
	);
	return 1;
}
