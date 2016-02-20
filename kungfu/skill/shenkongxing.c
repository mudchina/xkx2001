//Cracked by Roath
// shenkongxing, 身空行。
// Ryu, 11/14/96.

inherit SKILL;

string *dodge_msg = ({
	"$n默念忿怒咒，一式「誓言空」，一个筋斗从$N头上一翻而过，跳到$P身后。\n",
	"$n作舞立姿，忽左而右，脚踩「莲空」步，从$N的腋下穿到$P身後，绕过$N这一招。\n",
	"$n微笑中後退两步，身子一顿，一式「大安空」，跨腿朝边上一跳，$N一招击在空处。\n",
	"$n一式「佛空」，身子一侧，信步往左一踏，$N的进攻一下失去了方向，招数被化於无形。\n",
	"$n结跏趺坐，双手往$N肩上一按，一式「金刚空」跃起数尺，飘然落到一旁。\n",
	"$n一式「心空」，身形似有似无、若隐若现，$N这一招似乎击中$n，似乎又打在空处，浑不着力。\n",
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的精力太差了，不能练身空行。\n");
        me->receive_damage("jingli", 30);
        return 1;
}

