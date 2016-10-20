package com.lkd.tag;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.regex.Pattern;

import javax.servlet.jsp.JspException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.PageContext;
import javax.servlet.jsp.tagext.SimpleTagSupport;

public class ReadFileTag extends SimpleTagSupport {

	//相对于当前web应用的根路径的文件名
	private String src;
	public void setSrc(String src){
		this.src = src;
	}
	@Override
	public void doTag() throws JspException, IOException {
		// TODO Auto-generated method stub
		PageContext pageContext = (PageContext)getJspContext();
		InputStream inputStream = pageContext.getServletContext().getResourceAsStream(src);
		BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
		String string = null;
		while ((string = reader.readLine()) != null) {
//			string = Pattern.compile("<").matcher(string).replaceAll("&lt");
//			string = Pattern.compile(">").matcher(string).replaceAll("&gt");
			pageContext.getOut().println(string);
			pageContext.getOut().println("<br>");
			
		}
	}
}
