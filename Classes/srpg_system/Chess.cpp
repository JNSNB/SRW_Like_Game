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
        //�ж��ļ��Ƿ����  
        if(!cocos2d::FileUtils::getInstance()->isFileExist(jsonFilePath))  
        {  
            cocos2d::log("json file is not find [%s]",jsonFilePath);  
            return ;  
        }  
        //��ȡ�ļ����ݣ���ʼ��doc  
        std::string data=cocos2d::FileUtils::getInstance()->getStringFromFile(jsonFilePath);  
        doc.Parse<rapidjson::kParseDefaultFlags>(data.c_str());  
        //�ж϶�ȡ�ɹ���� �� �Ƿ�Ϊ�������� 
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
                //�����ȡ����Ԫ�أ������ı�������Ϊ���ã�  
                rapidjson::Value &v=chessArray[i]; 

                //�жϸ������Ƿ���ڣ�����֧�����ģ�UTF8��ʽ����  
                if(v.HasMember("battlefieldID") && v.HasMember("HP") && v.HasMember("EN") && v.HasMember("Move") )  
                {  
                    //��������ȡ����  
                    this->battlefieldID=v["battlefieldID"].GetInt();
                    this->HP=v["HP"].GetInt();
                    this->EN=v["EN"].GetInt();
                    this->Move=v["Move"].GetInt();
                    ICON=v["ICON"].GetString();

                    //cocos2d::log(A2U("ID:%d,����:%s,Ѫ��:%d,������:%d,������:%d,�ɴ�͸��:%s"),  
                    //    id,name.c_str(),hp,Defense,attack,(passable ? "true":"false"));  
                } 
            }
        }
        //for(unsigned int i=0;i<doc.Size();i++)  
        //{  
        //    //�����ȡ����Ԫ�أ������ı�������Ϊ���ã�  
        //    rapidjson::Value &v=doc[i]; 

        //    //�жϸ������Ƿ���ڣ�����֧�����ģ�UTF8��ʽ����  
        //    if(v.HasMember("battlefieldID") && v.HasMember("HP") && v.HasMember("EN") && v.HasMember("Move") )  
        //    {  
        //        //��������ȡ����  
        //        this->battlefieldID=v["battlefieldID"].GetInt();
        //        this->HP=v["HP"].GetInt();
        //        this->EN=v["EN"].GetInt();
        //        this->Move=v["Move"].GetInt();
        //        ICON=v["ICON"].GetString();

        //        //cocos2d::log(A2U("ID:%d,����:%s,Ѫ��:%d,������:%d,������:%d,�ɴ�͸��:%s"),  
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