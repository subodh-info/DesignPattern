#include <iostream>
#include <string>

class StockApp
{
    public:
    std::string m_xmlData;
    StockApp(std::string data)
    {
        m_xmlData = data;
    }
    std::string getXmlData()
    {
        return "<xml> " + m_xmlData + " </xml>";
    }
};

class AnalyticTool
{
    public:
    std::string m_jsonData;
    AnalyticTool(std::string jsonData)
    {
        m_jsonData = jsonData;
    }

    void analyzeData()
    {
        if(m_jsonData.find("json") != std::string::npos)
        {
            std::cout << "json data is proccessing ..... by Analytic tools" << std::endl;
        }
        else{
            std::cout << "Data is not proper format for processing !" << std::endl;
        }
    }
};

class AdapterPattern
{
    std::string m_data;
    public:
    AdapterPattern(std::string xmlData)
    {
        m_data = xmlData;
    }
    std::string getJsonDat(){
        // check xml data
        if(m_data.find("xml") != std::string::npos){
            int _index = m_data.find("<xml>");

            // replace with json
            m_data.replace(_index, 5, "{json:");
            
            // replace </xml>
            int index_ = m_data.find("</xml>");
            m_data.replace(index_, 6, "}");         
        }
        else{
            std::cout << "Getting invalid input for processing !!!" << std::endl;
            m_data = "";
        }
        return m_data;
    }
    
};

int main()
{
    StockApp app("Design Pattern");
    std::string xmlData = app.getXmlData();
    std::cout << xmlData << std::endl; // verify result return by app

    // change xml data into json
    AdapterPattern adapter(xmlData);
    std::string jsonData = adapter.getJsonDat();
    std::cout << jsonData << std::endl; // verify result return by adapter

    // process the json data
    AnalyticTool tool(jsonData);
    tool.analyzeData();

    return EXIT_SUCCESS;
}