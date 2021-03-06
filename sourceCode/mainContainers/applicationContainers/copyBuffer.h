#pragma once

#include "sceneObject.h"
#include "collection.h"
#include "collisionObject.h"
#include "distanceObject.h"
#include "ikGroup.h"
#include "pathPlanningTask_old.h"
#include "buttonBlock.h"
#include "luaScriptObject.h"
#include "dynMaterialObject.h"

class CCopyBuffer  
{
public:
    CCopyBuffer();
    virtual ~CCopyBuffer();

    void clearBuffer();
    int pasteBuffer(bool intoLockedScene);
    bool isBufferEmpty();
    void copyCurrentSelection(std::vector<int>* sel,bool fromLockedScene);
    void serializeCurrentSelection(CSer& ar,std::vector<int>* sel,C7Vector& modelTr,C3Vector& modelBBSize,float modelNonDefaultTranslationStepSize);
    bool isCopyForPasting();

    void memorizeBuffer();
    void restoreBuffer();
    void clearMemorizedBuffer();

    void _backupBuffers_temp();
    void _restoreBuffers_temp();
private:

    void _announceObjectWillBeErased(int objectID);
    void _announceGroupWillBeErased(int groupID);
    void _announceIkGroupWillBeErased(int ikGroupID);
    void _announceCollisionWillBeErased(int collisionID);
    void _announceDistanceWillBeErased(int distanceID);
    void _announce2DElementWillBeErased(int elementID);

    void _eraseObjectInBuffer(int objectID);
    void _erase2DElementInBuffer(int objectID);
    void _eraseLuaScriptInBuffer(int objectID);
    void _erasePathPlanningTaskInBuffer(int objectID);
    void _eraseCollisionInBuffer(int objectID);
    void _eraseDistanceInBuffer(int objectID);
    void _eraseCollectionInBuffer(int objectID);
    void _eraseIkObjectInBuffer(int objectID);
    void _eraseTextureObjectInBuffer(int objectID); 

    bool _copyIsForPasting;


    bool _bufferIsFromLockedScene;
    std::vector<CSceneObject*> objectBuffer;
    std::vector<CCollection*> groupBuffer;
    std::vector<CCollisionObject*> collisionBuffer;
    std::vector<CDistanceObject*> distanceBuffer;
    std::vector<CIkGroup*> ikGroupBuffer;
    std::vector<CPathPlanningTask*> pathPlanningTaskBuffer;
    std::vector<CButtonBlock*> buttonBlockBuffer;
    std::vector<CLuaScriptObject*> luaScriptBuffer;
    std::vector<CTextureObject*> textureObjectBuffer;

    // Following buffers are used TEMPORARILY when saving a model. They will always be empty before and after serialization
    std::vector<CSceneObject*> objectBuffer_tempSer;
    std::vector<CCollection*> groupBuffer_tempSer;
    std::vector<CCollisionObject*> collisionBuffer_tempSer;
    std::vector<CDistanceObject*> distanceBuffer_tempSer;
    std::vector<CIkGroup*> ikGroupBuffer_tempSer;
    std::vector<CPathPlanningTask*> pathPlanningTaskBuffer_tempSer;
    std::vector<CButtonBlock*> buttonBlockBuffer_tempSer;
    std::vector<CLuaScriptObject*> luaScriptBuffer_tempSer;
    std::vector<CTextureObject*> textureObjectBuffer_tempSer;



    bool _bufferIsFromLockedScene_memorized;
    std::vector<CSceneObject*> objectBuffer_memorized;
    std::vector<CCollection*> groupBuffer_memorized;
    std::vector<CCollisionObject*> collisionBuffer_memorized;
    std::vector<CDistanceObject*> distanceBuffer_memorized;
    std::vector<CIkGroup*> ikGroupBuffer_memorized;
    std::vector<CPathPlanningTask*> pathPlanningTaskBuffer_memorized;
    std::vector<CButtonBlock*> buttonBlockBuffer_memorized;
    std::vector<CLuaScriptObject*> luaScriptBuffer_memorized;
    std::vector<CTextureObject*> textureObjectBuffer_memorized;
};
