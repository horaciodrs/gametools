#ifndef __ANNIMATION__
#define __ANNIMATION__

#include "object.hpp"

namespace GT{

	class Animation : public GT::Object{

		private:
			int FrameWidth;
			int FrameCount;
			int CurrentFrame;
			bool Running;
		public:
			bool isRuning(void){return Running;}
			void Draw(void);
			void Begin(void);
			void End(void);
			Animation(std::string pId, int pFrameWidth, Application *pApp);
			~Animation();

	};

}

#endif