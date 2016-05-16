package ren.laughing.jianzhi;
/**
 * 懒汉式-修改2：双重检查锁定
 * 在getSingleton中做了两次null检查，确保了只有第一次调用单例的时候才会做同步，这样也是线程安全的，同时避免了每次都同步的性能损耗
 * @author Laughing_Lz
 * @time 2016年5月16日
 */
public class Singleton4 {
	private static Singleton4 singleton4 = null;
	//私有构造器
	private Singleton4(){
		
	}
	public static Singleton4 getSingleton(){
		if(singleton4 == null){
			synchronized (Singleton4.class) {//双检锁:只有第一次调用单例时候才会同步 (Singleton4.class 锁定的一定要是类吗？ singleton4实例行不行)
				if(singleton4 ==null){
					singleton4 = new Singleton4();
				}
			}
		}
		return singleton4;
	}
}
