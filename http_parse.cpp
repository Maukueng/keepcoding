//http报文解析
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void http_parse(const string& request, string& method, string& path, string& version, vector<pair<string, string>>& headers, string& body) {
    //请求头和请求体分割的地方
    size_t pos = request.find("\r\n\r\n");
    body = request.substr(pos + 4);
    string requestLineHeader = request.substr(0, pos);
    pos = requestLineHeader.find("\r\n");
    //分割请求行和请求体
    string requestLine = requestLineHeader.substr(0, pos);
    string requestHead = requestLineHeader.substr(pos + 2);
    //处理请求行
    pos = requestLine.find(" ");
    method = requestLine.substr(0, pos);
    requestLine = requestLine.substr(pos + 1);
    pos = requestLine.find(" ");
    path = requestLine.substr(0, pos);
    version = requestLine.substr(pos + 1);

    //处理请求头
    while (true) {
        pos = requestHead.find("\r\n");
        if (pos == string::npos) break;
        string header = requestHead.substr(0, pos);
        requestHead = requestHead.substr(pos + 2);
        pos = header.find(": ");
        string key = header.substr(0, pos);
        string value = header.substr(pos + 2);
        headers.push_back(make_pair(key, value));
    }
}

int main() {
    // HTTP 报文示例
    string http_requeset =
        "GET /index.html HTTP/1.1\r\n"
        "Host: www.example.com\r\n"
        "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:89.0) Gecko/20100101 Firefox/89.0\r\n"
        "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n"
        "Accept-Language: en-US,en;q=0.5\r\n"
        "Accept-Encoding: gzip, deflate, br\r\n"
        "Connection: keep-alive\r\n"
        "Upgrade-Insecure-Requests: 1\r\n"
        "\r\n";

    // 解析 HTTP 报文
    string method, path, version, body;
    vector<pair<string, string>> headers;
    http_parse(http_requeset, method, path, version, headers, body);
    cout << method << endl;
    cout << path << endl;
    cout << version << endl;
    for (auto head : headers) {
        cout << head.first << ":" << head.second << endl;
    }
    cout << body << endl;
    return 0;
}