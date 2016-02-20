// xgrep.c 
// write by JackyBoy@CuteRabbit Studio for SDXL & CCTX 1999/6/1
// 为了避免递归太深，请不要设置进入级别超过16级. JackyBoy
inherit F_CLEAN_UP;
int help();
int do_grep(string,string,int);
string resolvePath(string,int);

static string pattern;
static string result;

int main(object me, string arg)
{
	string  path,wild;
	int level;
	level=1;
	result="匹配文件有：\n";
	seteuid(geteuid(me));
	write("X grep 命令 v0.1  \nWrite By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1\n"+
		"主页：http://mud.yn.cninfo.net/jackyboy\n邮件：jackyboy@126.com\n");
    if (!arg) return help();
    if (sscanf(arg,"-d %s %s",path,pattern)!=2)
    {
    	if(sscanf(arg,"-d%d %s %s",level,path,pattern)!=3)
    		if(sscanf(arg,"%s %s",path,pattern)!=2)
    		{
    			write ("\n参数解析错误。\n\n");
    			return help();
    		}
    }
    else
    	level=15;//带-d参数默认级别为所有级
    if(level<0) level=1;
    if(level>15) level=15;
    //处理path分解出wild
    path=resolve_path(me->query("cwd"),path);
    write("未解析路径：\t"+path+"\n");
    //write("欲搜索字符串：\t"+pattern+"\n");
    write("搜索目录级别：\t"+level+"\n");
    wild=resolvePath(path,0);
    path=resolvePath(path,1);
    write("解析后路径：\t"+path+"\n");
    write("解析后通配符：\t"+wild+"\n\n");
    do_grep(path,wild,level);
    write("\n搜索结束。\n");
    write(result+"\n");
	return 1;
}

string resolvePath(string path,int op)
{
	string *dn,tmp;
	int i;
	if(path=="/")//对这个情况特殊处理
		return (op)?"/":"*";
	dn=explode(path,"/");
	if(op)//op为非0表示需要返回路径
	{
		//dn=dn-({dn[sizeof(dn)-1]});
		//tmp=implode(dn,"/")+"/";
		//上面的程序不好，不能对同名路径正确处理，比如不能在/log/log文件里搜索
		tmp="/";
		for(i=0;i<sizeof(dn)-1;i++)
		{
			//write("合并"+dn[i]+"\n");
			tmp+=dn[i]+"/";
		}
		return tmp;
	}
	else
		return dn[sizeof(dn)-1];
}
int do_grep(string path,string wild,int level)
{
	//int i;string *fs;
	string sbuffer,file;
	reset_eval_cost();//重新设置剩余执行时间，必须设置！
	if(this_player()->query("env/debug"))
		write("开始搜索"+path+wild+"\n");
	if(level<0)
	{
		//write("级别限制，不能再进入搜索。\n");
		return 0;
	}
	//for(i=0;i<(sizeof(fs=get_dir(path+wild))-1);i++)
	//	write(fs[i]+"\n");
	
	foreach(file in get_dir(path+wild))
	{
		//write("检查："+path+file+"\n");
		//write("file_size返回："+file_size(path+file)+"\n");
		if(file=="."||file=="..")
			continue;
		
		switch(file_size(path+file))
		{
			case -1:
				//无法读取该目录，跳过
				break;
			case -2:
				if(file!="."&&file!="..")
					do_grep(path+file+"/","*",level-1);
				break;
			default:
				//write("检查文件："+path+file+"\n");
				if(!sbuffer=read_file(path+file))
				//对太大的文件读取可能要失败！而且不能试图读取二进制文件，因为含有\0!
				{
					write("读文件"+path+file+"出错！\n");
					return 0;
				}
				if(strsrch(sbuffer,pattern)!=-1)
					result=result+"在"+path+file+"里找到"+pattern+"\n";//应该是记录下来，最后再输出
			/*
				if(strsrch(read_file(path+file),pattern)!=-1)
					write(path+file+"\n");
				break;
			*/
		}
		
	}
	return 1;
}

int help()
{
  write(@HELP

X grep 命令 v0.1  Write By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1
主页：http://mud.yn.cninfo.net/jackyboy
邮件：jackyboy@126.com


指令格式 : xgrep [-d[0-15]] 路径 想要搜索的字符串
此指令可让你在指定(除了目录，可以用通配符来指定)档案或目录里寻找含有要
搜索的字符串的文件，并将其位置显示出来。
注意，默认仅搜索当前目录！
已知BUG：
对二进制文件进行搜索将会出错，因为禁止将'\0'设置到一个string里！
HELP
    );
    return 1;
}
