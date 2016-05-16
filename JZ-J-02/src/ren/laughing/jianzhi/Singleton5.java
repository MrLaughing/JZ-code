package ren.laughing.jianzhi;

/**
 * 静态内部类：按需创建实例★
 * Singleton4虽然通过双检锁避免了同步的性能损耗
 * 但是有可能会过早的创建实例（比如调用Singleton4中存在的静态方法，并不需要实例），降低内存的使用效率
 * 而在这里则可以实现 按需创建实例
 * @author Laughing_Lz
 * @time 2016年5月16日
 */
public class Singleton5 {
	// 私有构造器
	private Singleton5() {

	}

	public static Singleton5 getSingleton() {
		return LazyGet.SINGLETON5;// 调用内部类来获取单例
	}
	//静态内部类
	private static class LazyGet {
		private static final Singleton5 SINGLETON5 = new Singleton5();
	}
}
