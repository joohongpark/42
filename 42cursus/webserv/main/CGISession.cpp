#include "CGISession.hpp"

CGISession::CGISession(HTTPData& data) : _pid(-2), _inputStream(-1), _outputStream(-1) {
    std::map<std::string, std::string> _envMap;
    _envMap[std::string("USER")] = std::string(std::getenv("USER"));
    _envMap[std::string("PATH")] = std::string(std::getenv("PATH"));
    _envMap[std::string("LANG")] = std::string(std::getenv("LANG"));
    _envMap[std::string("PWD")] = std::string(std::getenv("PWD"));
    _envMap[std::string("QUERY_STRING")] = data._URIQueryString;
    _envMap[std::string("REQUEST_METHOD")] = data._reqMethod;
    _envMap[std::string("CONTENT_TYPE")] = data._reqContentType;
    _envMap[std::string("CONTENT_LENGTH")] = data._reqContentLength;
    _envMap[std::string("SCRIPT_NAME")] = data._URIFilePath;
    _envMap[std::string("PATH_INFO")] = data._URIFilePath;
    _envMap[std::string("REQUEST_URI")] = data._originURI;
    _envMap[std::string("DOCUMENT_URI")] = data._reqURI;
    _envMap[std::string("DOCUMENT_ROOT")] = data._root;
    _envMap[std::string("SERVER_PROTOCOL")] = std::string("HTTP/1.1");
    _envMap[std::string("REQUEST_SCHEME")] = data._reqMethod;
    _envMap[std::string("GATEWAY_INTERFACE")] = std::string("CGI/1.1");
    _envMap[std::string("SERVER_SOFTWARE")] = std::string("webserv/") + std::string(WEBSERV_VERSION);
    _envMap[std::string("REMOTE_ADDR")] = data._clientIP;
    _envMap[std::string("REMOTE_PORT")] = data._clientPort;
    _envMap[std::string("SERVER_ADDR")] = data._hostIP;
    _envMap[std::string("SERVER_PORT")] = data._hostPort;
    _envMap[std::string("SERVER_NAME")] = data._serverName;
    _envMap[std::string("SCRIPT_FILENAME")] = data._resAbsoluteFilePath;
    for (std::map<std::string, std::string>::iterator iter = data._HTTPCGIENV.begin(); iter != data._HTTPCGIENV.end(); iter++) {
        _envMap[iter->first] = iter->second;
    }

    _arg[0] = const_cast<char*>(data._CGIBinary.c_str());
    _arg[1] = const_cast<char*>(data._resAbsoluteFilePath.c_str());
    if (data._URIQueryString.empty()) {
        _arg[2] = NULL;
    } else {
        _arg[2] = const_cast<char*>(data._URIQueryString.c_str());
    }
    _arg[3] = NULL;
    _env = generateEnvp(_envMap);
}

CGISession::~CGISession() {
    int status;
    if (_pid > 0) {
        waitpid(_pid, &status, WNOHANG);
        if (status & 0177) {
            kill(_pid, SIGTERM);
        }
    }
    if (_inputStream > 0 && close(_inputStream) == -1) {
        throw ErrorHandler("Can't close File Descriptor", ErrorHandler::ALERT, "CGISession::~CGISession");
    }
    if (_outputStream > 0 && close(_outputStream) == -1) {
        throw ErrorHandler("Can't close File Descriptor", ErrorHandler::ALERT, "CGISession::~CGISession");
    }
    if (_env != NULL) {
        int i = 0;
        while (_env[i] != NULL) {
            delete _env[i];
            i++;
        }
        delete _env;
    }
}

int & CGISession::getInputStream(void) {
    return (_inputStream);
}

int & CGISession::getOutputStream(void) {
    return (_outputStream);
}

void CGISession::makeCGIProcess(int inputfd) {
    int pairForI[2];
    int pairForO[2];
    int target;

    if (pipe(pairForI) == -1 || pipe(pairForO) == -1) {
        throw ErrorHandler("Can't make Pipe", ErrorHandler::ALERT, "CGISession::makeCGIProcess");
    }
    _inputStream = pairForI[1];
    _outputStream = pairForO[0];
    target = (inputfd != 0) ? inputfd : pairForI[0];
    if ((_pid = fork()) < 0) {
        throw ErrorHandler("Can't make Process", ErrorHandler::ALERT, "CGISession::makeCGIProcess");
    }
    if (_pid == 0) {
        if ((dup2(target, STDIN_FILENO) == -1) || (dup2(pairForO[1], STDOUT_FILENO) == -1)) {
            throw ErrorHandler("Can't duplicate File Descriptor", ErrorHandler::ALERT, "CGISession::makeCGIProcess");
        }
        if ((close(pairForI[1]) == -1) || (close(pairForO[0]) == -1)) {
            throw ErrorHandler("Can't close File Descriptor", ErrorHandler::ALERT, "CGISession::makeCGIProcess");
        }
        if (execve(_arg[0], _arg, _env) == -1) {
            throw ErrorHandler("Can't duplicate File Descriptor", ErrorHandler::NORMAL, "CGISession::makeCGIProcess");
        }
    } else {
        if ((close(pairForI[0]) == -1) || (close(pairForO[1]) == -1)) {
            throw ErrorHandler("Can't close File Descriptor", ErrorHandler::ALERT, "CGISession::makeCGIProcess");
        }
    }
    if (inputfd == 0) {
        close(_inputStream);
        _inputStream = 0;
    }
}

char** CGISession::generateEnvp(std::map<std::string, std::string>& arg) {
    char** rtn = new char*[arg.size() + 1];
    std::map<std::string, std::string>::iterator iter;
    std::string tmpString;
    int i = 0;
    for (iter = arg.begin(); iter != arg.end(); iter++) {
        tmpString = std::string(iter->first);
        tmpString += std::string("=");
        tmpString += std::string(iter->second);
        char* variable = new char[tmpString.size() + 1];
        std::strcpy(variable, tmpString.c_str());
        rtn[i] = variable;
        i++;
    }
    rtn[i] = NULL;
    return (rtn);
}
