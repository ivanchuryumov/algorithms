namespace drc {

	class Printable {
	public:
		virtual void Print() const = 0;
		virtual void PrintData() const = 0;
	};

	class DynamicConnectivity : Printable {
	public:
		DynamicConnectivity(const int size);
		virtual void Union(int p, int q) = 0;
		virtual const bool Connected(int p, int q) const = 0;
		virtual void Print() const;
		virtual void PrintData() const;
		~DynamicConnectivity();
	private:
		DynamicConnectivity(const DynamicConnectivity&);
		int* array;
		int arraySize;
	};

	class QuickFind : public DynamicConnectivity {
	public:
		QuickFind(const int size);
		void Union(int a, int b);
		const bool Connected(int a, int b) const;
	};

	class QuickUnion : public DynamicConnectivity {
	public:
		QuickUnion(const int size);
		void Union(int a, int b);
		const bool Connected(int a, int b) const;
	protected:
		int Root(int i) const;
	};

	class QuickUnionWeighted : public QuickUnion {
	public:
		QuickUnionWeighted(const int size);
		void Union(int a, int b);
		~QuickUnionWeighted();
	private:
		int* weights;
	};
}