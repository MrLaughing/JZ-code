package ren.laughing.jianzhi;
/**
 * 懒汉式-修改1：在方法调用上加了同步，虽然线程安全了，但是每次都要同步，会影响性能。
 * @author Laughing_Lz
 * @time 2016年5月16日
 */
public class Singleton3 {
	private static Singleton3 singleton3 = null;
	//私有构造器
	private Singleton3() {
		
	}
	public static synchronized Singleton3 getSingleton(){//synchronized 同步  防止多个线程同时访问这个方法, static 对这个类的所有对象实例起作用
		if(singleton3 == null){
			singleton3 = new Singleton3();
		}
		return singleton3;
	}
}
