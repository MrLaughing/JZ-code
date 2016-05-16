package ren.laughing.jianzhi;

/**
 * 饿汉式：在类创建的同时就已经创建好一个静态的对象供系统使用，以后不再改变，所以天生是线程安全的。
 * 
 * @author Laughing_Lz
 * @time 2016年5月16日
 */
public class Singleton1 {
	private static final Singleton1 singleton1 = new Singleton1();// 饿汉式，static直接创建实例,节省时间但是会一直占用内存,天生线程安全
	// 私有构造函数

	private Singleton1() {

	}

	public Singleton1 getSingleton() {
		return singleton1;
	}
}
