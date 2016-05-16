package ren.laughing.jianzhi;
/**
 * 懒汉式：在第一次调用的时候实例化自己 
 * 但是线程不安全
 * @author Laughing_Lz
 * @time 2016年5月16日
 */
public class Singleton2 {
	private static Singleton2 singleton2 = null;
	//私有构造函数
	private Singleton2(){
		
	}
	public Singleton2 getSingleton(){
		if(singleton2 == null){
			singleton2 = new Singleton2();
		}
		return singleton2;
	}
	
}
