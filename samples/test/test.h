
class CHelloWorldHandler : public CRequestHandlerT<CHelloWorldHandler>
{
public:
	BEGIN_REPLACEMENT_METHOD_MAP(CHelloWorldHandler)
		REPLACEMENT_METHOD_ENTRY("Hello", OnHello)
	END_REPLACEMENT_METHOD_MAP()

	HTTP_CODE ValidateAndExchange()
	{
		m_HttpResponse.SetContentType("text/html");
		return HTTP_SUCCESS;
	}

protected:
	// Here is an example of how to use a replacement tag with the stencil processor
	HTTP_CODE OnHello(void)
	{
		m_HttpResponse << "Hello World!";
		return HTTP_SUCCESS;
	}
}; // class CHelloWorldHandler