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

	//��ǩ���߼�ʵ��Ӧ�ñ�д���÷�����
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
	//jsp������ã��Ѵ���jspҳ���PageContext������
	//PageContext���Ի�ȡjspҳ������8����������
	//����jspҳ��������ı�ǩ�������������
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
