#include "Chess.h"
#include "spine\Json.h" 
#include "cocos-ext.h" 
namespace SRPG_SYSTEM
{
    Chess::Chess(void)
    {
    }

    Chess::Chess(std::string jsonFilePath)
    {
        std::string ICON;

        //std::string jsonFilePath="Json_test_1.json";  
        rapidjson::Document doc;
        //判断文件是否存在  
        if(!cocos2d::FileUtils::getInstance()->isFileExist(jsonFilePath))  
        {  
            cocos2d::log("json file is not find [%s]",jsonFilePath);  
            return ;  
        }  
        //读取文件数据，初始化doc  
        std::string data=cocos2d::FileUtils::getInstance()->getStringFromFile(jsonFilePath);  
        doc.Parse<rapidjson::kParseDefaultFlags>(data.c_str());  
        //判断读取成功与否 和 是否为数组类型 
        auto docHPE = doc.HasParseError();
        auto docIA = doc.IsArray();
        if (doc.HasParseError())  
        {  
            cocos2d::log("get json data err!");  
            return;  
        }
        if (doc.HasMember("chess") || !doc.IsObject())
        {
            rapidjson::Value &chessArray=doc["chess"];
            if(!doc.IsArray())
            {
                cocos2d::log("get json data err!");  
                return;
            }
            for(unsigned int i=0;i<chessArray.Size();i++)  
            {  
                //逐个提取数组元素（声明的变量必须为引用）  
                rapidjson::Value &v=chessArray[i]; 

                //判断各属性是否存在（可以支持中文（UTF8格式））  
                if(v.HasMember("battlefieldID") && v.HasMember("HP") && v.HasMember("EN") && v.HasMember("Move") )  
                {  
                    //按属性提取数据  
                    this->battlefieldID=v["battlefieldID"].GetInt();
                    this->HP=v["HP"].GetInt();
                    this->EN=v["EN"].GetInt();
                    this->Move=v["Move"].GetInt();
                    ICON=v["ICON"].GetString();

                    //cocos2d::log(A2U("ID:%d,名称:%s,血量:%d,防御力:%d,攻击力:%d,可穿透性:%s"),  
                    //    id,name.c_str(),hp,Defense,attack,(passable ? "true":"false"));  
                } 
            }
        }
        //for(unsigned int i=0;i<doc.Size();i++)  
        //{  
        //    //逐个提取数组元素（声明的变量必须为引用）  
        //    rapidjson::Value &v=doc[i]; 

        //    //判断各属性是否存在（可以支持中文（UTF8格式））  
        //    if(v.HasMember("battlefieldID") && v.HasMember("HP") && v.HasMember("EN") && v.HasMember("Move") )  
        //    {  
        //        //按属性提取数据  
        //        this->battlefieldID=v["battlefieldID"].GetInt();
        //        this->HP=v["HP"].GetInt();
        //        this->EN=v["EN"].GetInt();
        //        this->Move=v["Move"].GetInt();
        //        ICON=v["ICON"].GetString();

        //        //cocos2d::log(A2U("ID:%d,名称:%s,血量:%d,防御力:%d,攻击力:%d,可穿透性:%s"),  
        //        //    id,name.c_str(),hp,Defense,attack,(passable ? "true":"false"));  
        //    } 
        //}
        this->sprite = cocos2d::Sprite::create(ICON);
    }

    Chess::~Chess(void)
    {
    }

    void Chess::selected2Menu(){}
    void Chess::move2TilePos(cocos2d::Vec2 newTilePos){}
    void Chess::battleWith(Chess *enemyChess){}
    void Chess::showStatus(){}
    void Chess::standBy(){}
    void Chess::calculateMovement(cocos2d::TMXTiledMap *tileMap){}


}