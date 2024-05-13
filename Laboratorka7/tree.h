#pragma once
#include <vector>
#include <QPoint>
#include <chrono>
namespace Tree {
	struct Data {
		int val;
        int level;
        int pos;
        int posX{0};
        int posY{0};
        bool new_node{false};
		bool is_search_result = false;
	};
	
	class Node
	{
	public:
        const int DrawingSize{34};
        const QPoint start_pos{360,150};

		Node* _left = nullptr, * _right = nullptr;
		static int left_nodes;
		static int right_nodes;
		
        Data _data;
		unsigned int exec_time = NULL;

		bool Contain(int number);
		void GetSortedVector(std::vector<int>& a);
		void Insert(Data NewData);
		void ResetSearchResultFlag();
		Node* Search(int key);
		
        void ResetLastLabel();

        std::vector<Data> SetPositionOfNodesForVisualization();
        std::vector<QPoint> GetVectorOfLinesBetwenNodes();

		template<typename Func>
		void measureExecutionTime(Func&& func);
		Node(Data NewData);
		~Node();

	private:
           
		Node* search(int key, Node* node) ; 
		Node* root_{ nullptr };
        void ReturnDataVector(std::vector<Data>& vector);
        void LoopForLinesConnection(std::vector<QPoint>& vec);
        void SetDataForDrawing(Node& root);
        void SetPos(int& pos);
        void SetLevel(int& level);
		
	};
}
