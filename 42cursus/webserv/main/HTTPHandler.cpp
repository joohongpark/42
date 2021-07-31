#include "HTTPHandler.hpp"

HTTPHandler::Buffer::Buffer(size_t bufferSize) {
    _buffer = new char[bufferSize];
    if (_buffer == NULL) {
        throw ErrorHandler("Error: memory alloc error", ErrorHandler::CRITICAL, "HTTPHandler::Buffer::Buffer");
    }
}

HTTPHandler::Buffer::~Buffer() {
    delete [] _buffer;
}

char* HTTPHandler::Buffer::operator*(void) {
    return (_buffer);
}

HTTPHandler::HTTPHandler(int connectionFd, NginxConfig::ServerBlock serverConf, const NginxConfig::GlobalConfig& nginxConf) : _serverConf(serverConf), _nginxConf(nginxConf) {
	_connectionFd = connectionFd;
	_headerString = std::string("");
}

HTTPHandler::~HTTPHandler() {}

void HTTPHandler::setGeneralHeader(std::string status) {
    static char timeBuffer[48];
    time_t rawtime;

    std::time(&rawtime);
    struct tm* timeinfo = std::gmtime(&rawtime);
    std::strftime(timeBuffer, 48, "%a, %d %b %Y %H:%M:%S %Z", timeinfo);

    _headerString = status;
    _headerString += "\r\n";

    _headers["Date"] = std::string(timeBuffer);
    _headers["Server"] = std::string("webserv/") + std::string(WEBSERV_VERSION);
    _headers["Connection"] = std::string("close");
}

void HTTPHandler::convertHeaderMapToString(void) {
    std::map<std::string, std::string>::iterator iter;
    for (iter = _headers.begin(); iter != _headers.end(); ++iter) {
        size_t duplicateIdentifier = (iter->first).find("@");
        if (duplicateIdentifier != std::string::npos) {
            _headerString += (iter->first).substr(duplicateIdentifier + 1);
        } else {
            _headerString += iter->first;
        }
        _headerString += ": ";
        _headerString += iter->second;
        _headerString += "\r\n";
    }
    _headerString += "\r\n";
}

std::pair<std::string, std::string> HTTPHandler::getHTTPHeader(const std::string& str, std::size_t& endPos) {
    std::pair<std::string, std::string> pair;
    pair.first = Parser::getIdentifier(str, endPos, ": ", false);
    if (pair.first.empty()) {
        throw ErrorHandler("Error: HTTP Header error.", ErrorHandler::NORMAL, "HTTPHandler::getHTTPHeader");
    }
    endPos += 2;
    pair.second = Parser::getIdentifier(str, endPos, "\r\n", false);
    if (pair.second.empty()) {
        throw ErrorHandler("Error: HTTP Header error.", ErrorHandler::NORMAL, "HTTPHandler::getHTTPHeader");
    }
    endPos += 2;
    return (pair);
}

void HTTPHandler::requestAlert(std::string ip, std::string port, std::string serverPort, std::string path, std::string method) {
	static char timeStringBuffer[20];
	time_t rawtime;
	struct tm *timeinfo;
	std::time(&rawtime);
	timeinfo = std::localtime(&rawtime);
	std::strftime(timeStringBuffer, 20, "%Y/%m/%d %H:%M:%S", timeinfo);
	std::cout << "\x0d\033[0;32m[";
	std::cout << timeStringBuffer;
	std::cout << "]\033[0m ";
    std::cout << "\033[0;33m[" << method << " @ " << serverPort << "]\033[0m ";
    std::cout << ip << ":" << port << path << std::endl;
}
