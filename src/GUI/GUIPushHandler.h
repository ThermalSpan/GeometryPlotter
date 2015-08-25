class GUIPushHandler;

typedef std::shared_ptr <GUIPushHandler> pushHandPtr;
typedef std::list <pushHandPtr> pushHandList;
typedef std::unique_ptr <pushHandList> pushHandListPtr;

class GUIPushHandler
    {
    public:
        virtual void update () = 0;
    };