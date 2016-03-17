
class CRedirHandler : public CRequestHandlerT<CRedirHandler>
{
public:
	HTTP_CODE ValidateAndExchange()
	{
		m_spServerContext->SendRedirectResponse("http://mygalileo/atlserver/readme.html");
		return HTTP_SUCCESS;
	}
}; // class CHelloWorldHandler