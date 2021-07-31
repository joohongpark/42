#ifndef HTTPRESPONSEHANDLER_HPP
#define HTTPRESPONSEHANDLER_HPP

#include <ctime>
#include <iostream>

#include "FileController.hpp"
#include "HTTPHandler.hpp"
#include "CGISession.hpp"

#include "NginxConfig.hpp"
#include "HTMLBody.hpp"

#ifndef WEBSERV_VERSION
#define WEBSERV_VERSION "0.0.0"
#endif

class HTTPResponseHandler : public HTTPHandler {
    private:
        HTTPResponseHandler();
    public:
        HTTPResponseHandler(int connectionFd, const NginxConfig::ServerBlock& serverConf, const NginxConfig::GlobalConfig& nginxConf);
        virtual ~HTTPResponseHandler();
        typedef enum e_Phase {
            FIND_RESOURCE, 
            PRE_STATUSCODE_CHECK, 
            GET_STATIC_HTML, 
            GET_FILE, 
            REDIRECT, 
            CGI_RUN, 
            DATA_SEND_LOOP, 
            CGI_RECV_HEAD_LOOP, 
            CGI_RECV_BODY_LOOP, 
            FINISH,
            FINISH_RE
        } Phase;
        virtual HTTPResponseHandler::Phase process(HTTPData& data, long bufferSize);
        int getCGIfd(void);
    private:
        std::string getMIME(const std::string& extension);
        bool isCGI(std::string& URI);
        std::string getIndexPage(const std::string& absPath);
        std::string getErrorPage(const std::string& absPath);
        bool isErrorPageList(int statusCode, std::vector<std::string>& errorPageVec);
        void setGeneralHeader(HTTPData& data);
        void setHTMLHeader(const HTTPData& data);
        void setCGIConfigMap();
        NginxConfig::LocationBlock getMatchingLocationConfiguration(const HTTPData& data);
        HTTPResponseHandler::Phase setInformation(HTTPData& data, int statusCode, const std::string& absPath);
        HTTPResponseHandler::Phase setFileInDirectory(HTTPData& data, const std::string& absLocPath);
        HTTPResponseHandler::Phase handleProcess(std::string tmpFilePath, std::string tmpLocPath, std::string absFilePath, HTTPData& data);

    private:
        Phase _phase;
        FileController::Type _type;
        std::string _staticHtml;
        FileController* _file;
        CGISession* _cgi;
        NginxConfig::LocationBlock _locConf;
        std::string _indexPage;
        std::string _errorPage;
        std::string _CGIReceive;
        std::vector<std::string> _errorPageList;
        std::map<std::string, std::string> _cgiConfMap;
};

#endif
