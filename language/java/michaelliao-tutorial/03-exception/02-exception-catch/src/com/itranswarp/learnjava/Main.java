package com.itranswarp.learnjava;

/**
 * Learn Java from https://www.liaoxuefeng.com/
 * 
 * @author liaoxuefeng
 */
public class Main {

	public static void main(String[] args) {
		String a = "12";
		String b = "x9";
		// TODO: 捕获异常并处理
		int c = stringToInt(a);
		int d = stringToInt(b);
		System.out.println(c * d);
	}

	static int stringToInt(String s) {
		try {
			return Integer.parseInt(s);
		} catch (NumberFormatException e) {
			System.out.println(e);
			return Integer.valueOf(0);
		}

	}
}
