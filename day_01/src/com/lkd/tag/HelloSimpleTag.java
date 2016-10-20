package com.lkd.tag;

import java.io.IOException;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.jsp.JspContext;
import javax.servlet.jsp.JspException;
import javax.servlet.jsp.PageContext;
import javax.servlet.jsp.tagext.JspFragment;
import javax.servlet.jsp.tagext.JspTag;
import javax.servlet.jsp.tagext.SimpleTag;

public class HelloSimpleTag implements SimpleTag {
	PageContext pageContext;
	private String value;
	private String count;
	

	public void setValue(String value) {
		this.value = value;
	}

	public void setCount(String count) {
		this.count = count;
	}

	//标签体逻辑实际应该编写到该方法中
	@Override
	public void doTag() throws JspException, IOException {
		// TODO Auto-generated method stub
		System.out.println("value:" + value + ",count:" + count);
		
		HttpServletRequest request = (HttpServletRequest)pageContext.getRequest();
		pageContext.getOut().println("hello" + request.getParameter("name"));
	}

	@Override
	public JspTag getParent() {
		// TODO Auto-generated method stub
		System.out.println("----------getParent");
		return null;
	}

	@Override
	public void setJspBody(JspFragment arg0) {
		// TODO Auto-generated method stub
		System.out.println("----------setJspBody");
	}
	//jsp引擎调用，把代表jsp页面的PageContext对象传入
	//PageContext可以获取jsp页面其他8个隐含对象
	//凡是jsp页面可以做的标签处理器可以完成
	@Override
	public void setJspContext(JspContext arg0) {
		// TODO Auto-generated method stub
		System.out.println("----------setJspContext");
		System.out.println(arg0 instanceof PageContext);
		this.pageContext = (PageContext)arg0;
	}

	@Override
	public void setParent(JspTag arg0) {
		// TODO Auto-generated method stub
		System.out.println("----------setParent");
	}

}
