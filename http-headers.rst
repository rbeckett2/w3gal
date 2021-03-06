.. _http-headers:

http-headers
============

The following request headers are recognized by w3gal and are available to your web application by the m_HttpRequest.GetServerVariable or .GetQueryParams methods

See the ShowMe project for an example

- cache-control
- connection
- date
- keep-alive
- pragma
- trailer
- transfer-encoding
- upgrade
- via
- warning
- allow
- content-length
- content-type
- content-encoding
- content-language
- content-location
- content-MD5
- content-range
- expires
- last-modified
- accept-ranges
- accept-charset
- accept-encoding
- accept-language
- authorization
- cookie
- expect
- from
- host
- if-match
- if-modified-since
- if-none-match
- if-range
- if-unmodified-since
- max-forwards
- proxy-authorization
- referer
- range
- te
- translate
- user-agent
- https - can be "off" or "on"
- method
- x-actual-bytes - actual bytes received on the network interface
- x-local-address - 169.254.227.228
- x-remote-address - 169.254.227.228
- url - http://mygalileo:80/atlserver/readme.html?AnyQueryString

The following reponse http headers are recognized by w3gal and are available to your web application for sending using the m_spServerContext->SendResponseHeaders method

- cache-control
- connection
- date
- keep-alive
- pragma
- trailer
- transfer-encoding
- upgrade
- via
- warning
- allow
- content-type
- content-encoding
- content-language
- content-location
- content-MD5
- content-range
- expires
- last-modified
- accept-ranges
- age
- etag
- location
- proxy-authentication
- retry-after
- server
- set-cookie
- vary
- www-authenticate


.. toctree::
   :maxdepth: 2